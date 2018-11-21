# Promisc

Simple tool to set your nic into promiscuous mode and to then go in the background.

## Tested on

Linux, FreeBSD, Illumos/Solaris

## Requirements

Headers for libpcap, and libpcap itself.

## Usage

```
./promisc [iface]
```

iface is optional. When iface is not specified, it will take the default interface (which has the default route).

## Use cases

Sometimes jail/zone-like functionality doesn't seem to route packets unless interfaces are set to IF_PROMISC. This is a better way to force your nic into promiscuous mode instead of running tcpdump or sniff in the background.
