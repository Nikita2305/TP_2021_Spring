#!/bin/bash

content_dir=$1
extension=$2
dest_dir=$3
arch_name=$4

for file in `find $content_dir -name \*.$extension`
do
    len=${#content_dir}
    short_path=${file:len}
    mkdir -p $dest_dir/`dirname $short_path`
    cp $file $dest_dir/$short_path
done

tar -cf $arch_name $dest_dir

echo done
