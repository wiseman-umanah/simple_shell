#!/bin/bash

if [ "$(id -u)" != "0" ]
then
        echo "Sorry, you are not root."
        exit 1
fi

MAN_PATH="/usr/local/share/man/man1"

mkdir -p "${MAN_PATH}"

cp "man/hsh.1" "${MAN_PATH}"

echo -e "Updating man database.."

mandb

echo -e "All set."
