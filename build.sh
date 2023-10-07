#!/bin/bash

echo "Started building TaskCLI..."

if which g++ >/dev/null; then
  g++ main.cpp -o TaskCLI
  echo "Finished building!"
  echo "to run use './TaskCLI'"
else
  echo "g++ is not installed."
fi