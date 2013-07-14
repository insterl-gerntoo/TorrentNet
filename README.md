TorrentNet
==========

An idea for a decentralized, peer-to-peer internet.

The Idea
--------
Use bittorrent technology and DHT to create an internet.
Similar to freenet and gnunet, but aims to be MUCH more dynamic, since the static-content-only thing seems
	to be the second major pitfall of these systems, the first being the insanely slow speeds, which I haven't
	yet figured out how to overcome.

Buttwhy?
--------
"Doesn't \<insert program, protocol, etc here\> do this already?"
	Yes, most likely.  Is it suddenly illegal to start programming projects on the internet if similar projects exist?             
"So why not just make a fork of \<insert program, protocol, etc here\>?"
	If you want to, go for it.  I'd rather get an example of this system working on its own, before trying to figure out how
		to shape some other program into something that does what I want.

What it do
----------
Every user is a node, who can download and redistribute objects, and help the nodes connected to it with DHT work.

Objects can be data (files), scripts (with a special "safe" runtime environment), or just collections of references
	to other objects (this would essentially be a website)

Since objects can be scripts, nodes can share the costs of of both bandwidth and computing, so creating a website with heavy traffic on
	torrentnet can be done with any low-powered computer, rather than requiring a powerful webserver.

Nodes can connect to objects and treat them like peers, sending and receiving data, and objects can make these same connections with other
	objects.

Nodes can do proxying for other nodes, so under conditions of censorship, as long as a node can find a path to a node that is uncensored,
	it can bypass censorship.
