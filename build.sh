#!/bin/bash

current_directory=$(pwd)

echo "Started building TaskCLI... ($current_directory)"

if which g++ >/dev/null; then
  g++ main.cpp -o TaskCLI -I $current_directory/include
  echo "Finished building!"
  echo "to run use './TaskCLI'"
else
  echo "g++ is not installed."
fi