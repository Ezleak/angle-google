// GENERATED FILE - DO NOT EDIT.
// Generated by gen_vk_internal_shaders.py.
//
// Copyright 2018 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// shaders/gen/OverlayCull.comp.00000001.inc:
//   Pre-generated shader for the ANGLE Vulkan back-end.

#pragma once
constexpr uint8_t kOverlayCull_comp_00000001[] = {
    0x1f,0x8b,0x08,0x00,0x00,0x00,0x00,0x00,0x02,0xff,0x5d,0x92,0x5b,0x6b,0x53,0x51,
    0x10,0x85,0xe7,0x9c,0xdc,0xaa,0x82,0xd6,0x44,0x09,0xb6,0x69,0xa3,0x06,0xfa,0x62,
    0x29,0x82,0x17,0x04,0x09,0xda,0x97,0x44,0x68,0x8a,0x4a,0x1f,0x6c,0x6b,0xc5,0x6a,
    0x2f,0x20,0x58,0xb1,0x54,0x0d,0x6a,0x2c,0xd5,0x14,0xfd,0x11,0xfe,0x03,0x1f,0xc4,
    0x3f,0x27,0x5e,0x40,0x70,0xd6,0xce,0x77,0xe2,0x36,0x07,0x86,0x39,0xb3,0x66,0xf6,
    0xda,0x6b,0x66,0x76,0x2e,0x6d,0x94,0x2c,0x97,0xd8,0x51,0x1b,0xb3,0x4f,0x36,0xf8,
    0x4e,0x5a,0x6a,0x09,0xbe,0x89,0xbf,0xe9,0xfe,0x98,0x15,0x03,0xde,0xee,0x2c,0x75,
    0xe6,0xf6,0x5e,0x6c,0xce,0x5d,0xbe,0x72,0x51,0xf5,0xc7,0x2d,0x17,0xce,0x29,0x77,
    0xc2,0x4a,0x56,0x70,0x9f,0x77,0xdb,0x79,0xf4,0xe4,0x99,0xf0,0xb2,0x5b,0xcb,0x6d,
    0xdc,0xcf,0xe7,0x03,0x9f,0x05,0xbe,0x04,0x6b,0x3b,0x5a,0x0e,0xfc,0x66,0x93,0xc4,
    0xf2,0xc5,0x70,0xc6,0xec,0x96,0x33,0xd6,0xd0,0xd6,0xc0,0xb7,0xfd,0x4e,0x61,0x29,
    0xf5,0xd3,0xee,0xcf,0x0f,0x73,0x83,0xf8,0x5c,0xc4,0xdf,0x82,0x7f,0x82,0x78,0x6d,
    0xa4,0x7e,0x8d,0xfa,0x8c,0x5b,0xf1,0x19,0x72,0xdb,0x9c,0x55,0x5c,0xf1,0x1b,0xd3,
    0x50,0x9b,0x0b,0x5d,0xeb,0xff,0xb4,0xd7,0x48,0xeb,0x59,0xce,0x57,0x3d,0x2e,0xa1,
    0x3f,0x25,0x1e,0x27,0xce,0x85,0xba,0x7c,0x98,0x41,0x42,0x7f,0xd7,0x89,0xcb,0x60,
    0x17,0xe0,0xab,0xc0,0xa7,0xfa,0x53,0xe4,0x8a,0xf0,0x55,0xf9,0xcf,0x47,0xf5,0x13,
    0xcc,0xb5,0xc6,0xfc,0xaa,0x60,0xd3,0xcc,0x6a,0x12,0xae,0x29,0x74,0xd5,0xb8,0x7b,
    0x2a,0xd4,0xfc,0xeb,0xa5,0x4e,0x2f,0x99,0x96,0x7a,0xd4,0x9b,0xce,0x37,0x86,0x7d,
    0x99,0xeb,0x4a,0x6d,0x06,0x4d,0x97,0xdc,0xcf,0x90,0xcb,0x34,0xdd,0xa0,0xe7,0xac,
    0xc7,0xd6,0x48,0x8f,0x0b,0x6e,0x63,0x6e,0xb3,0xbe,0x63,0xcd,0xac,0x03,0xb6,0x10,
    0xe6,0x7d,0xc4,0x56,0xe9,0x33,0xb1,0xff,0xbf,0x14,0xcd,0xd2,0x73,0x1f,0x6c,0x95,
    0x7b,0x14,0xaf,0x45,0xbb,0x78,0xe8,0xbe,0x3e,0xa2,0x6b,0x0b,0xce,0x59,0x8f,0xb4,
    0x83,0x6d,0x66,0xb5,0x85,0x5d,0x75,0x3d,0x29,0xf3,0x35,0x7a,0xf8,0xe9,0x88,0xde,
    0x76,0x93,0x7d,0xb6,0xe9,0xe7,0xb6,0x2b,0x2f,0x85,0x77,0x3a,0xc0,0xda,0x9c,0x11,
    0xff,0x21,0x7d,0x2d,0x92,0x57,0x7f,0x07,0x60,0x77,0xc0,0x85,0xcd,0x3b,0xa6,0x1d,
    0x3f,0xe5,0x1d,0x54,0xb8,0x47,0x5a,0x77,0xc0,0xe7,0x3d,0xd2,0xec,0x9f,0x0f,0x7b,
    0x1f,0xe4,0x9a,0xbc,0x87,0x5d,0x72,0x77,0x9d,0x4b,0xe7,0xf6,0xc0,0x2c,0xc2,0x5e,
    0x82,0xa9,0xb7,0x6f,0x8e,0x69,0x5f,0xaf,0xa8,0x55,0xee,0x87,0x77,0xda,0xe3,0xcc,
    0x6f,0xe7,0x55,0xae,0xeb,0xd6,0xa3,0xff,0x6e,0xd4,0xef,0x6b,0xb8,0x76,0xa3,0x7e,
    0xc5,0xa9,0x77,0xf0,0x86,0xbc,0x7a,0xfc,0xec,0x3c,0xba,0xe7,0x2d,0xf8,0x2f,0xe7,
    0xc9,0xf8,0xe4,0xbf,0x3b,0x9b,0xf2,0xef,0xd0,0x52,0xa0,0xb6,0x8b,0x9e,0x7e,0xa4,
    0x47,0x35,0xfb,0x6e,0x7d,0xce,0xef,0x47,0x7a,0x0e,0x22,0x3d,0x29,0x3b,0xfb,0x8a,
    0x9e,0xf7,0xe4,0x17,0x23,0x3d,0x1f,0xc0,0xa5,0x27,0xe3,0xeb,0x47,0x7a,0x0e,0xd1,
    0xd4,0xa3,0x56,0x77,0x2d,0x25,0x85,0x30,0xeb,0x8f,0xbc,0x6d,0xd5,0x7c,0x61,0x8e,
    0xf7,0xd8,0x47,0x05,0xdd,0x2b,0x91,0x6e,0xe5,0x96,0xdd,0x56,0xb8,0x67,0x99,0xbd,
    0xe9,0xcd,0x3e,0xe0,0xbd,0xf6,0x78,0xab,0xeb,0xbc,0x95,0x6c,0x67,0x8f,0xb9,0x2f,
    0xde,0xe3,0x06,0x58,0x12,0x66,0x5c,0x0a,0x9a,0x36,0xa9,0xdd,0x40,0x43,0x25,0xfc,
    0xe7,0x03,0xff,0x3a,0x79,0xf5,0x9a,0x69,0x90,0xff,0xe3,0x0c,0xd7,0xdc,0xfe,0x02,
    0xd4,0xf4,0x04,0xb7,0x08,0x06,0x00,0x00
};

// Generated from:
//
// #version 450 core
//
// #extension GL_EXT_samplerless_texture_functions : require
//
// #extension GL_KHR_shader_subgroup_ballot : require
//
// layout(local_size_x = 64, local_size_y = 1, local_size_z = 1)in;
//
// layout(set = 0, binding = 0, rgba32ui)uniform writeonly uimage2D culledWidgetsOut;
//
// layout(set = 0, binding = 1)uniform WidgetCoordinates
// {
//     uvec4 coordinates[32 + 32];
// };
//
// uvec2 cullWidgets(const uint offset, const uvec2 blockCoordLow, const uvec2 blockCoordHigh)
// {
//     const uint localId = gl_LocalInvocationID . x;
//     const uvec4 widgetCoords = coordinates[offset + localId];
//
//     const bool intersects = widgetCoords . x < widgetCoords . z &&
//                             all(lessThan(widgetCoords . xy, blockCoordHigh))&&
//                             all(greaterThanEqual(widgetCoords . zw, blockCoordLow));
//
//     return subgroupBallot(intersects). xy;
//
// }
//
// void main()
// {
//
//     const uvec2 outCoord = gl_WorkGroupID . xy;
//     const uvec2 blockCoordLow = outCoord * uvec2(8, 8);
//     const uvec2 blockCoordHigh = blockCoordLow + uvec2(8, 8);
//
//     uvec2 culledWidgets;
//
//     culledWidgets = cullWidgets(0, blockCoordLow, blockCoordHigh);
//
//     if(gl_LocalInvocationID . x == 0)
//     {
//         imageStore(culledWidgetsOut, ivec2(outCoord), uvec4(culledWidgets, 0, 0));
//     }
// }