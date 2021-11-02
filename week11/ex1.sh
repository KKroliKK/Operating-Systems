sudo dd if=/dev/zero of=lofs.img bs=50M count=2
losetup -fP lofs.img
sudo mkfs.ext4 ./lofs.img

mkdir lofsdisk
mount -o loop lofs.img lofsdisk