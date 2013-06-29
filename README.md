TorrentNet
==========

An idea for a decentralized, peer-to-peer internet.

The Idea
--------
Use bittorrent technology and DHT to create an internet.

Every user is a node, who can download and redistribute objects, and help the nodes connected to it with DHT work.

Objects can be data (files), scripts (with a special "safe" runtime environmnet), or just collections of references
	to other objects (this would essentially be a website)

Since objects can be scripts, nodes can share the costs of of both bandwidth and computing, so creating a website with heavy traffic on
	torrentnet can be done with any low-powered computer, rather than requiring a powerful webserver.
	
Nodes can do proxying for other nodes, so under conditions of censorship, as long as a node can find a path to a node that is uncensored,
	it can bypass censorship.
