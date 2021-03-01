make clean
make 
make copySDcard_files
cd card 
./create_card.sh hello_world.bin
#sudo ./write_card.sh card.Rpi3.RevB.baremetal.img
cat comments.txt
