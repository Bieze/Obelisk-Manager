#!/usr/bin/bash

ARCHS=( amd64 386 )
OS=(windows)

PACKAGE="main"
VERSION="$(git describe --exact-match --tags $(git log -n1 --pretty='%h'))"
COMMIT_HASH="$(git rev-parse --short HEAD)"

LDFLAGS="-X '${PACKAGE}.AppVersion=${VERSION}' \
         -X '${PACKAGE}.GitHash=${COMMIT_HASH}'"


for GOARCH in "${ARCHS[@]}"
do

	env GOOS=${OS} GOARCH=${GOARCH} go build -o bin/Obelisk-Manager-${GOARCH}-${OS} -ldflags "${LDFLAGS}"

done
