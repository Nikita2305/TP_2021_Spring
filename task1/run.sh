#!/bin/bash

content_dir=`realpath $1`
extension=$2
dest_dir=`realpath $3`
arch_name=$4
len=${#content_dir}

mkdir -p $dest_dir

for file in `find $content_dir -name \*.$extension`
do
    absolute_file_path=`realpath $file`
    short_path=${absolute_file_path:len}
    mkdir -p $dest_dir/`dirname $short_path`
    cp $absolute_file_path $dest_dir/$short_path
done

tar -czf $arch_name -P $dest_dir

echo done
