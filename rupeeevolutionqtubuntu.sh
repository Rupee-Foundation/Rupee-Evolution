#!/bin/bash
TEMP=/tmp/answer$$
whiptail --title "Rupee Evolution [RUPEE]"  --menu  "Ubuntu 16.04/18.04 QT Wallet :" 20 0 0 1 "Compile Rupee Evolution QT Ubuntu 16.04" 2 "Update Rupee Evolution QT 16.04 to v3.4 latest" 3 "Compile Rupee Evolution QT Ubuntu 18.04" 4 "Update Rupee Evolution QT 18.04 to v3.4 latest" 2>$TEMP
choice=`cat $TEMP`
case $choice in
1) echo 1 "Compiling Rupee Evolution QT Ubuntu 16.04"

echo "Updating linux packages"
sudo apt-get update -y && sudo apt-get upgrade -y

sudo apt-get install -y git unzip build-essential libssl-dev libdb++-dev libboost-all-dev libqrencode-dev libminiupnpc-dev libevent-dev autogen automake  libtool libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools qt5-default

echo "Installing RupeeEvolution Wallet"
git clone https://github.com/Rupee-Foundation/Rupee-Evolution
cd Rupee-Evolution || exit
git checkout master
git pull

#echo "Change line in rupeeevolution-qt.pro from stdlib=c99 to stdlib=gnu99"
#sed -i 's/c99/gnu99/' ~/rupeeevolution/rupeeevolution-qt.pro

qmake "USE_QRCODE=1" "USE_UPNP=1" rupeeevolution-qt.pro
make

echo "Get Chaindata"
cd ~/.rupeeevolution || exit
rm -rf database txleveldb smsgDB
#wget http://d.hashbag.cc/chaindata.zip
#unzip chaindata.zip
#wget https://github.com/Rupee-Foundation/rupeeevolution/releases/download/v3.3.7/chaindata1799510.zip
#unzip chaindata1799510.zip
#rm chaindata1799510.zip
Echo "Back to Compiled QT Binary Folder"
cd ~/Rupee-Evolution/src
                ;;
2) echo 2 "Update RupeeEvolution QT"
echo "Updating RupeeEvolution Wallet"
cd ~/Rupee-Evolution || exit
git checkout master
git pull

#echo "Change line in rupeeevolution-qt.pro from stdlib=c99 to stdlib=gnu99"
#sed -i 's/c99/gnu99/' ~/rupeeevolution/rupeeevolution-qt.pro

qmake "USE_QRCODE=1" "USE_UPNP=1" rupeeevolution-qt.pro
make
echo "Back to Compiled QT Binary Folder"
cd ~/Rupee-Evolution
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

echo "Installing Rupee Evolution Wallet"
git clone https://github.com/Rupee-Foundation/Rupee-Evolution
cd Rupee-Evolution
git checkout master
git pull

#echo "Change line in rupeeevolution-qt.pro from stdlib=c99 to stdlib=gnu99"
#sed -i 's/c99/gnu99/' ~/rupeeevolution/rupeeevolution-qt.pro

qmake "USE_UPNP=1" "USE_QRCODE=1" OPENSSL_INCLUDE_PATH=/usr/local/ssl/include OPENSSL_LIB_PATH=/usr/local/ssl/lib rupeeevolution-qt.pro
make

#echo "Get Chaindata"
#cd ~/.rupeeevolution
#rm -rf database txleveldb smsgDB
#wget http://d.hashbag.cc/chaindata.zip
#unzip chaindata.zip
#wget https://github.com/Rupee-Foundation/rupeeevolution/releases/download/v3.3.7/chaindata1799510.zip
#unzip chaindata1799510.zip
#rm chaindata1799510.zip
Echo "Back to Compiled QT Binary Folder"
cd ~/Rupee-Evolution/src
                ;;
4) echo 4 "Update Rupee Evolution QT 18.04"
echo "Updating Rupee Evolution Wallet"
cd ~/Rupee-Evolution || exit
git checkout master
git pull

#echo "Change line in rupeeevolution-qt.pro from stdlib=c99 to stdlib=gnu99"
#sed -i 's/c99/gnu99/' ~/rupeeevolution/rupeeevolution-qt.pro

qmake "USE_UPNP=1" "USE_QRCODE=1" OPENSSL_INCLUDE_PATH=/usr/local/ssl/include OPENSSL_LIB_PATH=/usr/local/ssl/lib rupeeevolution-qt.pro
make
echo "Back to Compiled QT Binary Folder"
cd ~/Rupee-Evolution
                ;;
esac
echo Selected $choice
