При старте создать и запустить файловую систему(инструкция для linux):
dd if=/dev/zero of new.fs bs=1024 count=10240
mkfs.hfsplus /new.fs
mkdir /mnt/newspo
mount /new.fs /mnt/newspo
