//
// Copyright 2024 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

#ifndef LIBANGLE_RENDERER_WGPU_WGPU_UTILS_H_
#define LIBANGLE_RENDERER_WGPU_WGPU_UTILS_H_

#include <dawn/webgpu_cpp.h>
#include <stdint.h>

#include "libANGLE/Caps.h"
#include "libANGLE/Error.h"
#include "libANGLE/angletypes.h"

#define ANGLE_WGPU_TRY(context, command)                                                     \
    do                                                                                       \
    {                                                                                        \
        auto ANGLE_LOCAL_VAR = command;                                                      \
        if (ANGLE_UNLIKELY(::rx::webgpu::IsWgpuError(ANGLE_LOCAL_VAR)))                      \
        {                                                                                    \
            (context)->handleError(GL_INVALID_OPERATION, "Internal WebGPU error.", __FILE__, \
                                   ANGLE_FUNCTION, __LINE__);                                \
            return angle::Result::Stop;                                                      \
        }                                                                                    \
    } while (0)

#define ANGLE_GL_OBJECTS_X(PROC) \
    PROC(Buffer)                 \
    PROC(Context)                \
    PROC(Framebuffer)            \
    PROC(Query)                  \
    PROC(Program)                \
    PROC(ProgramExecutable)      \
    PROC(Sampler)                \
    PROC(Texture)                \
    PROC(TransformFeedback)      \
    PROC(VertexArray)

#define ANGLE_EGL_OBJECTS_X(PROC) \
    PROC(Display)                 \
    PROC(Image)                   \
    PROC(Surface)                 \
    PROC(Sync)

namespace rx
{

class ContextWgpu;
class DisplayWgpu;

#define ANGLE_PRE_DECLARE_WGPU_OBJECT(OBJ) class OBJ##Wgpu;

ANGLE_GL_OBJECTS_X(ANGLE_PRE_DECLARE_WGPU_OBJECT)
ANGLE_EGL_OBJECTS_X(ANGLE_PRE_DECLARE_WGPU_OBJECT)

namespace webgpu
{
template <typename T>
struct ImplTypeHelper;

#define ANGLE_IMPL_TYPE_HELPER(frontendNamespace, OBJ) \
    template <>                                        \
    struct ImplTypeHelper<frontendNamespace::OBJ>      \
    {                                                  \
        using ImplType = rx::OBJ##Wgpu;                \
    };
#define ANGLE_IMPL_TYPE_HELPER_GL(OBJ) ANGLE_IMPL_TYPE_HELPER(gl, OBJ)
#define ANGLE_IMPL_TYPE_HELPER_EGL(OBJ) ANGLE_IMPL_TYPE_HELPER(egl, OBJ)

ANGLE_GL_OBJECTS_X(ANGLE_IMPL_TYPE_HELPER_GL)
ANGLE_EGL_OBJECTS_X(ANGLE_IMPL_TYPE_HELPER_EGL)

#undef ANGLE_IMPL_TYPE_HELPER_GL
#undef ANGLE_IMPL_TYPE_HELPER_EGL

template <typename T>
using GetImplType = typename ImplTypeHelper<T>::ImplType;

template <typename T>
GetImplType<T> *GetImpl(const T *glObject)
{
    return GetImplAs<GetImplType<T>>(glObject);
}

constexpr size_t kUnpackedDepthIndex   = gl::IMPLEMENTATION_MAX_DRAW_BUFFERS;
constexpr size_t kUnpackedStencilIndex = gl::IMPLEMENTATION_MAX_DRAW_BUFFERS + 1;
constexpr uint32_t kUnpackedColorBuffersMask =
    angle::BitMask<uint32_t>(gl::IMPLEMENTATION_MAX_DRAW_BUFFERS);
// WebGPU image level index.
using LevelIndex = gl::LevelIndexWrapper<uint32_t>;

enum class RenderPassClosureReason
{
    NewRenderPass,

    InvalidEnum,
    EnumCount = InvalidEnum,
};

struct ClearValues
{
    wgpu::Color clearColor;
    uint32_t depthSlice;
};

class ClearValuesArray final
{
  public:
    ClearValuesArray();
    ~ClearValuesArray();

    ClearValuesArray(const ClearValuesArray &other);
    ClearValuesArray &operator=(const ClearValuesArray &rhs);

    void store(uint32_t index, ClearValues clearValues);
    gl::DrawBufferMask getColorMask() const;
    void reset()
    {
        mValues.fill({});
        mEnabled.reset();
    }
    void reset(size_t index)
    {
        mValues[index] = {};
        mEnabled.reset(index);
    }
    const ClearValues &operator[](size_t index) const { return mValues[index]; }

    bool empty() const { return mEnabled.none(); }
    bool any() const { return mEnabled.any(); }

    bool test(size_t index) const { return mEnabled.test(index); }

  private:
    gl::AttachmentArray<ClearValues> mValues;
    gl::AttachmentsMask mEnabled;
};

void EnsureCapsInitialized(const wgpu::Device &device, gl::Caps *nativeCaps);

DisplayWgpu *GetDisplay(const gl::Context *context);
wgpu::Device GetDevice(const gl::Context *context);
wgpu::Instance GetInstance(const gl::Context *context);
wgpu::RenderPassColorAttachment CreateNewClearColorAttachment(wgpu::Color clearValue,
                                                              uint32_t depthSlice,
                                                              wgpu::TextureView textureView);

bool IsWgpuError(wgpu::WaitStatus waitStatus);
bool IsWgpuError(WGPUBufferMapAsyncStatus mapBufferStatus);
}  // namespace webgpu

namespace wgpu_gl
{
gl::LevelIndex getLevelIndex(webgpu::LevelIndex levelWgpu, gl::LevelIndex baseLevel);
gl::Extents getExtents(wgpu::Extent3D wgpuExtent);
}  // namespace wgpu_gl

namespace gl_wgpu
{
webgpu::LevelIndex getLevelIndex(gl::LevelIndex levelGl, gl::LevelIndex baseLevel);
wgpu::TextureDimension getWgpuTextureDimension(gl::TextureType glTextureType);
wgpu::Extent3D getExtent3D(const gl::Extents &glExtent);
}  // namespace gl_wgpu

}  // namespace rx

#endif  // LIBANGLE_RENDERER_WGPU_WGPU_UTILS_H_
