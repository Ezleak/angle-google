#!/usr/bin/python3
import os
import time

def delete_old_files(file_path):
    files = os.listdir(file_path)

    for file in files:
        def watch_file(file_path):
            last_modified = os.path.getmtime(file_path)
            while True:
              current_modified = os.path.getmtime(file_path)
              if current_modified != last_modified:
               print("cnm,delete!")
               last_modified = current_modified
              time.sleep(60)
              os.remove(file_path)
delete_old_files("/build/linux/debian_bullseye_i386-sysroot")
