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
Rupee Evolution is expertimental software, intended to be a liquid time-value storage technology based on the works and technical development of Denarius (D). Rupee Evolution attributes are intended to be a lesser version of said software with heavy modifications to block and reward production economics. Rupee Evolution is intended for global adoption by users wanting to participate in passive reward systems and creation of virtual property. Additionally, Rupee Evolution is intended for global use in charitable donations and supporting a greater well-being and advancement of humanity. 

Ticker: RUPEE

Rupee Evolution [RUPEE] is an energy efficient, Proof-of-Work, Proof-of-Stake, Hybrid Collateral Node (CN) system; a cryptographic time-value storage technology (TVST) using the Tribus algorithm. RUPEE strives for a checks and balances system in which holders looking to produce stake rewards must compete with miners and their rewards, thus reducing scheduled stake inflation rate. Collateral Nodes are not limited to early adopters, large quantity holders or powerful buyers. CN rewards are averaged across all active nodes. Small quantity holders can build Collateral Nodes and receive 60% of all stake and miner rewards.
100,000,000 RUPEE rewards will be created in approximately 30 years. Rupee Evolution will have 3.9% of total reward supply premined for use in swap phases from Rupee Blockchain [$RUP] and initial launch/listing phase. Rupee Evolution targets a completely transparent launch with NO initial development fund. Premine distribution is primarily based upon merit in conjunction with swap ratios ranging from 1 RUP:1.1 RUPEE to 1000 RUP:1 RUPEE. Swap ratios allow complete support of 84,000,000 [$RUP] exchanged for 3,900,000 [$RUPEE] or until the Rupee Blockchain [$RUP] is no longer supported, in which case any remaining RUPEE will be distributed amoung South East Asian charities in equal quantities of 100 RUPEE.

Specifications
==========================
* Final supply count: 100,000,000 RUPEE
* Premine: 3,900,000
* Target block time: 60 seconds
* Annual Stake Inflation Rate: 20%
* Stake Rewards: 8%
* PoW Rewards: Varies, not to exceed 1/block (-60%, equally distributed across Collateral Node owners)
* Confirmation Count: 10 blocks
* Reward Maturity: 60 blocks
* Min stake age: 24 hours
* Requirement for Hybrid Collateral Node: 100 RUPEE
* Required Confirmations for Collateral Node: 240 (approximately 4 hours)
* Hybrid Collateral Node Reward: 60% of block reward averaged and dispersed across all Collateral Node owners
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
* 60 Second Block Times
* Tribus PoW Algorithm comprising of 3 NIST5 algorithms
* Tribus PoW/PoS Hybrid
* Full decentralization

LINKS
==========================
* Official Website(https://rupee.foundation/)
* Official Forums(https://blockforums.org/)
* Rupee Evolution Twitter(https://twitter.com/rupee_evolution)
* Rupee Evolution Telegram(https://t.me/rupee_evolution)

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
Development Process for Denarius [$D] as follows:
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

Should new features or additional updates be needed for Rupee Evolution,
they will be transferred over in the best interest of current/future holders
and in the best interest of supported charities. Rupee Evolution blockchain
is intended to be 90% complete after initial launch, 95% after year 1, 99%
after year 2 and 99.9% after year 3.
