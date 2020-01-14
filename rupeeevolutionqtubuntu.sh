#!/bin/bash
TEMP=/tmp/answer$$
whiptail --title "RupeeEvolution [RUPEE]"  --menu  "Ubuntu 16.04/18.04 QT Wallet :" 20 0 0 1 "Compile RupeeEvolution QT Ubuntu 16.04" 2 "Update RupeeEvolution QT 16.04 to v3.4 latest" 3 "Compile RupeeEvolution QT Ubuntu 18.04" 4 "Update RupeeEvolution QT 18.04 to v3.4 latest" 2>$TEMP
choice=`cat $TEMP`
case $choice in
1) echo 1 "Compiling RupeeEvolution QT Ubuntu 16.04"

echo "Updating linux packages"
sudo apt-get update -y && sudo apt-get upgrade -y

sudo apt-get install -y git unzip build-essential libssl-dev libdb++-dev libboost-all-dev libqrencode-dev libminiupnpc-dev libevent-dev autogen automake  libtool libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools qt5-default

echo "Installing RupeeEvolution Wallet"
git clone https://github.com/Rupee-Foundation/rupeeevolution
cd rupeeevolution || exit
git checkout master
git pull

#echo "Change line in rupeeevolution-qt.pro from stdlib=c99 to stdlib=gnu99"
#sed -i 's/c99/gnu99/' ~/rupeeevolution/rupeeevolution-qt.pro

qmake "USE_QRCODE=1" "USE_UPNP=1" rupeeevolution-qt.pro
make

echo "Populate rupeeevolution.conf"
mkdir ~/.rupeeevolution
echo -e "nativetor=0\naddnode=rupeeevolution.host\naddnode=rupeeevolution.win\naddnode=rupeeevolution.pro\naddnode=triforce.black" > ~/.rupeeevolution/rupeeevolution.conf

echo "Get Chaindata"
cd ~/.rupeeevolution || exit
rm -rf database txleveldb smsgDB
#wget http://d.hashbag.cc/chaindata.zip
#unzip chaindata.zip
#wget https://github.com/Rupee-Foundation/rupeeevolution/releases/download/v3.3.7/chaindata1799510.zip
#unzip chaindata1799510.zip
#rm chaindata1799510.zip
Echo "Back to Compiled QT Binary Folder"
cd ~/rupeeevolution/src
                ;;
2) echo 2 "Update RupeeEvolution QT"
echo "Updating RupeeEvolution Wallet"
cd ~/rupeeevolution || exit
git checkout master
git pull

#echo "Change line in rupeeevolution-qt.pro from stdlib=c99 to stdlib=gnu99"
#sed -i 's/c99/gnu99/' ~/rupeeevolution/rupeeevolution-qt.pro

qmake "USE_QRCODE=1" "USE_UPNP=1" rupeeevolution-qt.pro
make
echo "Back to Compiled QT Binary Folder"
cd ~/rupeeevolution
                ;;
3) echo 3 "Compile RupeeEvolution QT Ubuntu 18.04"
echo "Updating linux packages"
sudo apt-get update -y && sudo apt-get upgrade -y

sudo apt-get install -y git unzip build-essential libdb++-dev libboost-all-dev libqrencode-dev libminiupnpc-dev libevent-dev autogen automake libtool libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools qt5-default

echo "Downgrade libssl-dev"
sudo apt-get install make
wget https://www.openssl.org/source/openssl-1.0.1j.tar.gz
tar -xzvf openssl-1.0.1j.tar.gz
cd openssl-1.0.1j
./config
make depend
sudo make install
sudo ln -sf /usr/local/ssl/bin/openssl `which openssl`
cd ~
openssl version -v

echo "Installing RupeeEvolution Wallet"
git clone https://github.com/Rupee-Foundation/rupeeevolution
cd rupeeevolution
git checkout master
git pull

#echo "Change line in rupeeevolution-qt.pro from stdlib=c99 to stdlib=gnu99"
#sed -i 's/c99/gnu99/' ~/rupeeevolution/rupeeevolution-qt.pro

qmake "USE_UPNP=1" "USE_QRCODE=1" OPENSSL_INCLUDE_PATH=/usr/local/ssl/include OPENSSL_LIB_PATH=/usr/local/ssl/lib rupeeevolution-qt.pro
make

echo "Populate rupeeevolution.conf"
mkdir ~/.rupeeevolution
echo -e "nativetor=0\naddnode=rupeeevolution.host\naddnode=rupeeevolution.win\naddnode=rupeeevolution.pro\naddnode=triforce.black" > ~/.rupeeevolution/rupeeevolution.conf

#echo "Get Chaindata"
#cd ~/.rupeeevolution
#rm -rf database txleveldb smsgDB
#wget http://d.hashbag.cc/chaindata.zip
#unzip chaindata.zip
#wget https://github.com/Rupee-Foundation/rupeeevolution/releases/download/v3.3.7/chaindata1799510.zip
#unzip chaindata1799510.zip
#rm chaindata1799510.zip
Echo "Back to Compiled QT Binary Folder"
cd ~/rupeeevolution/src
                ;;
4) echo 4 "Update RupeeEvolution QT 18.04"
echo "Updating RupeeEvolution Wallet"
cd ~/rupeeevolution || exit
git checkout master
git pull

#echo "Change line in rupeeevolution-qt.pro from stdlib=c99 to stdlib=gnu99"
#sed -i 's/c99/gnu99/' ~/rupeeevolution/rupeeevolution-qt.pro

qmake "USE_UPNP=1" "USE_QRCODE=1" OPENSSL_INCLUDE_PATH=/usr/local/ssl/include OPENSSL_LIB_PATH=/usr/local/ssl/lib rupeeevolution-qt.pro
make
echo "Back to Compiled QT Binary Folder"
cd ~/rupeeevolution
                ;;
esac
echo Selected $choice
