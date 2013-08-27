//Basic info neccessary to identify, contact, and manage a node
class NodeInfo{
	UID uid;
	IP_Port ip_and_portnum;
	Timestamp last_activity;
};

//This will manage our list of nodes, hopefully
class NodeList{
	private:
		//The array with the actual node data
		NodeInfo all_nodes[39];
		
		//The eight nodes with IDs closest to ours
		NodeInfo *closest_nodes[8];
		
		//IDs for reference in the distant_nodes list
		UID comparison_ids[31];
		//The list of 31 equally spaced nodes for quick lookup of stuff
		NodeInfo *distanced_nodes[31];
		
		UID this_node_id;
		
		void fill_comparison_ids(void);
		
		void put_in_closest(NodeInfo *node);
		void put_in_distanced(NodeInfo *node);
	public:
		NodeList(UID this_node);
		NodeInfo* find_closest(UID &to_find);
		void list_closest(UID &to_find, NodeInfo *&node_list, int &list_size);
		
		void add_node(NodeInfo &newnode);
};

//This will do keep-alive on nodes, keeping the list fresh
//It might be a good idea to run it in a separate thread
class NodeListManager{
	private:
		void ping_nodes(void);
		void check_lists(void);
	public:
		NodeListManager(void);
		run();
};
