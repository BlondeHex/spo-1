При старте создать и запустить файловую систему(инструкция для linux):
<br/>
dd if=/dev/zero of new.fs bs=1024 count=10240
  <br/>
mkfs.hfsplus /new.fs
  <br/>
mkdir /mnt/newspo
  <br/>
mount /new.fs /mnt/newspo
