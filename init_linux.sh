#!/bin/bash
git submodule update -i
pushd dependencies/vstsdk
git submodule update -i
popd