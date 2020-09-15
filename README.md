# RupeeEvolution [RUPEE]
Tribus Algo PoW/PoS Hybrid Cryptocurrency

![logo](https://github.com/Rupee-Foundation/Rupee-Evolution/blob/master/src/qt/res/icons/rupeeevolution-256.png?raw=true)

[![GitHub version](https://img.shields.io/github/release/Rupee-Foundation/Rupee-Evolution.svg)](https://badge.fury.io/gh/Rupee-Foundation%2FRupee-Evolution)
[![License: GPL v3](https://img.shields.io/badge/License-MIT-blue.svg)](https://github.com/Rupee-Foundation/Rupee-Evolution/blob/master/COPYING)
[![RupeeEvolution downloads](https://img.shields.io/github/downloads/Rupee-Foundation/Rupee-Evolution/total.svg?maxAge=2592000)](https://github.com/Rupee-Foundation/Rupee-Evolution/releases)
[![Join the chat at https://discord.gg/AcThv2y](https://img.shields.io/badge/Discord-Chat-blue.svg?logo=discord)](https://discord.gg/AcThv2y)

[![HitCount](http://hits.dwyl.io/Rupee-Foundation/Rupee-Evolution.svg)](http://hits.dwyl.io/Rupee-Foundation/Rupee-Evolution)
<a href="https://discord.gg/rqQ9fUW"><img src="https://discordapp.com/api/guilds/334361453320732673/embed.png" alt="Discord server" /></a>

![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/Rupee-Foundation/Rupee-Evolution.svg) ![GitHub repo size in bytes](https://img.shields.io/github/repo-size/Rupee-Foundation/Rupee-Evolution.svg)

[![Snap Status](https://build.snapcraft.io/badge/Rupee-Foundation/Rupee-Evolution.svg)](https://build.snapcraft.io/user/Rupee-Foundation/Rupee-Evolution)

[![Build Status](https://travis-ci.org/Rupee-Foundation/Rupee-Evolution.svg?branch=master)](https://travis-ci.org/Rupee-Foundation/Rupee-Evolution)

[![Build history](https://buildstats.info/travisci/chart/Rupee-Foundation/Rupee-Evolution?branch=master)](https://travis-ci.org/Rupee-Foundation/Rupee-Evolution?branch=master)

Intro
==========================
RupeeEvolution is a true optional anonymous, untraceable, and secure hybrid cryptocurrency.

Ticker: RUPEE

RupeeEvolution [RUPEE] is an anonymous, untraceable, energy efficient, Proof-of-Work (New Tribus Algorithm) and Proof-of-Stake cryptocurrency.
84,000,000 RUPEE will be created in approx. about 15 years during the PoW phase. RupeeEvolution had a 26.19% Premine of 22,000,000 RUPEE for SWAP, distribution, and marketing.

Specifications
==========================
* Total number of coins: 84,000,000 RUPEE
* Ideal block time: 60 seconds
* Stake interest: 10% annual static inflation
* Confirmations: 10 blocks
* Maturity: 40 blocks
* Min stake age: 24 hours
* Cost of Hybrid Fortuna Stakes: 8,400 RUPEE
* Hybrid Fortuna Stake Reward: 70% of the current block reward
* P2P Port: 64630, Testnet Port: 64631
* RPC Port: 64634, Testnet RPC Port: 64635
* Fortuna Stake Port: 64638, Testnet Port: 64639

Technology
==========================
* Hybrid PoW/PoS Fortuna Stakes
* Stealth addresses
* Ring Signatures (16 Recommended)
* Native Optional Tor Onion Node (-nativetor=1)
* Encrypted Messaging
* Multi-Signature Addresses & TXs
* Atomic Swaps using UTXOs (BIP65 CLTV)
* BIP39 Support (Coin Type 114)
* Proof of Data (Image/Data Timestamping)
* Fast 15 Second Block Times
* Tribus PoW Algorithm comprising of 3 NIST5 algorithms
* Tribus PoW/PoS Hybrid
* Full decentralization

LINKS
==========================
* Official Website(https://rupeeevolution.io/)
* Official Forums(https://rupeeevolutiontalk.org/)
* RupeeEvolution Twitter(https://twitter.com/rupeeevolutioncoin)
* RupeeEvolution Discord Chat(https://discord.gg/C64HXbc)

rupeeevolutionqtubuntu.sh by Buzzkillb
===========================
Compile the latest RupeeEvolution QT (Graphical Wallet) Ubuntu 16.04 or Ubuntu 18.04.1

Credits to Buzzkillb for the creation of the original bash script, original repository: https://github.com/buzzkillb/denarius-qt/

Compiles RupeeEvolution QT Ubuntu 16.04 or 18.04, Grabs latest chaindata, and populates rupeeevolution.conf with addnodes or can update a previous compile to the latest master branch.  
```bash -c "$(wget -O - https://raw.githubusercontent.com/RupeeEvolution/rupeeevolution/master/rupeeevolutionqtubuntu.sh)"```  

To turn on nativetor in rupeeevolution.conf  
```nativetor=1```  

Development process
===========================

Developers work in their own trees, then submit pull requests when
they think their feature or bug fix is ready.

The patch will be accepted if there is broad consensus that it is a
good thing.  Developers should expect to rework and resubmit patches
if they don't match the project's coding conventions (see coding.txt)
or are controversial.

The master branch is regularly built and tested, but is not guaranteed
to be completely stable. Tags are regularly created to indicate new
stable release versions of RupeeEvolution.

Feature branches are created when there are major new features being
worked on by several people.

From time to time a pull request will become outdated. If this occurs, and
the pull is no longer automatically mergeable; a comment on the pull will
be used to issue a warning of closure. The pull will be closed 15 days
after the warning if action is not taken by the author. Pull requests closed
in this manner will have their corresponding issue labeled 'stagnant'.

Issues with no commits will be given a similar warning, and closed after
15 days from their last activity. Issues closed in this manner will be
labeled 'stale'.
