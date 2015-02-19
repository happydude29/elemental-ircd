/*
Command migrate-7 helps network staff migrate a network running Elemental-IRCd 6.6.2
to Elemental-IRCd 7.0 by getting a copy of the network channel state into a json
file on the disk. It will also be able to "replay" the network state into another
installation of Elemental-IRCd 7.0.

Because of the kind of data this tool needs to collect, it needs a server link to work.
*/
package main

import (
	"flag"
)

var (
	dataFileName = flag.String("datafile", "network.json", "file to dump to or load from")

	serverName  = flag.String("servername", "migrate-7.elemental-ircd.int", "server name to use in linking")
	serverID    = flag.String("sid", "8ZX", "server ID to use in linking")
	connHost    = flag.String("connhost", "127.0.0.1", "server to connect to")
	connPort    = flag.Int("connport", 6697, "port to connect on")
	connPass    = flag.String("connpass", "thebird", "password to use in linking")
	connUsesTLS = flag.Bool("use-ssl", true, "connect with SSL to the uplink")

	saveDataAction   = flag.Bool("save", false, "save network state?")
	replayDataAction = flag.Bool("replay", false, "replay network state?")
)

func main() {
	flag.Parse()
}
