#!/bin/bash
set -e
set -o pipefail

ARCHIVE_PATH=gcc-arm-none-eabi-9-2020-q2-update-x86_64-linux.tar.bz2

cd $(dirname "$0")
if ! [ -e "$ARCHIVE_PATH" ]; then
    wget "https://developer.arm.com/-/media/Files/downloads/gnu-rm/9-2020q2/$ARCHIVE_PATH"
fi
tar xf "$ARCHIVE_PATH"
rm "$ARCHIVE_PATH"
ln -sf $(realpath ./gcc-arm-none-eabi-9-2020-q2-update) arm
# XXX
