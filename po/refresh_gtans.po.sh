#!/bin/sh

PATH=../src:$PATH /usr/bin/xgettext --default-domain=gtans --directory=.. \
  --add-comments --keyword=_ --keyword=N_ \
  --files-from=list
