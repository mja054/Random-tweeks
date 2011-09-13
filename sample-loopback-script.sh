#!/bin/bash

set -ex
# alias lp_dev=loopback_device

lp_dev=`losetup -f`
losetup $lp_dev /export/auth
echo "mounting /mount/swift ....."
sleep 1
mount -t xfs -oloop $lp_dev /mount/swift
if [ $? -eq 0 ]
then
        echo "mounting /mount/swift on $lp_dev completed."
else
        echo "mounting /mount/swift failed."
fi
sleep 1

lp_dev=`losetup -f`
losetup $lp_dev /export/swift-test
echo "mounting /mount/sw-test ....."
sleep 1
mount -t xfs -o loop $lp_dev /mount/sw-test
if [ $? -eq 0 ]
then
        echo "mounting /mount/sw-test on $lp_dev completed."
else
        echo "mounting /mount/sw-test failed."
fi

lp_dev=`losetup -f`
losetup $lp_dev /export/ufo
echo "mounting /mount/ufo ....."
sleep 1
mount -t xfs -o loop $lp_dev /mount/ufo
if [ $? -eq 0 ]
then
        echo "mounting /mount/sw-test on $lp_dev completed."
else
        echo "mounting /mount/sw-test failed."
fi

lp_dev=`losetup -f`
losetup $lp_dev /export/test2
echo "mounting /mount/test2 ....."
sleep 1
mount -t xfs -o loop $lp_dev /mount/test2
if [ $? -eq 0 ]
then
        echo "mounting /mount/sw-test2 on $lp_dev completed."
else
        echo "mounting /mount/sw-test2 failed."
fi
