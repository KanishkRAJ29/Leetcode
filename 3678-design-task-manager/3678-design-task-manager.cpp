class TaskManager {
public:
    unordered_map<int,int> t_u;   // taskId -> userId
    unordered_map<int,int> t_p;   // taskId -> priority
    map<int,set<int>> p_task;     // priority -> ordered set of taskIds

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            add(t[0], t[1], t[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        // If re-adding an existing taskId, remove old placement first
        if (t_p.count(taskId)) {
            rmv(taskId);
        }
        t_u[taskId] = userId;
        t_p[taskId] = priority;
        p_task[priority].insert(taskId);
    }
    
    void edit(int taskId, int newPriority) {
        auto it = t_p.find(taskId);
        if (it == t_p.end()) return;                 // task not present → ignore
        int old = it->second;
        if (old == newPriority) return;              // nothing to do
        auto pit = p_task.find(old);
        if (pit != p_task.end()) {
            pit->second.erase(taskId);
            if (pit->second.empty()) p_task.erase(pit);
        }
        it->second = newPriority;
        p_task[newPriority].insert(taskId);
    }
    
    void rmv(int taskId) {
        auto itp = t_p.find(taskId);
        if (itp == t_p.end()) return;                // task not present → ignore
        int old = itp->second;
        t_p.erase(itp);
        t_u.erase(taskId);
        auto pit = p_task.find(old);
        if (pit != p_task.end()) {
            pit->second.erase(taskId);
            if (pit->second.empty()) p_task.erase(pit);
        }
    }
    
    int execTop() {
        if (p_task.empty()) return -1;               // <-- guard: nothing to execute
        auto it = p_task.rbegin();                   // highest priority
        // set at this priority must be non-empty by invariant
        int task = *it->second.rbegin();             // tie-break: largest taskId
        int ans = t_u[task];
        rmv(task);
        return ans;                                  // return userId of executed task
    }
};
