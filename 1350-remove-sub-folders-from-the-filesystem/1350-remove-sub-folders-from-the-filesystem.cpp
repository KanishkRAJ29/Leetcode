
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> result;
        
        
        // Sort the folders to ensure that subfolders come after their parent folders
        sort(folder.begin(), folder.end());
        
        // Keep track of the last added folder to avoid adding subfolders
        string lastAdded = "";

        for (const auto& currentFolder : folder) {
            // Check if the current folder is a subfolder of the last added folder
            if (lastAdded != "" && currentFolder.find(lastAdded + "/") == 0) {
                // It's a subfolder, skip it
                continue;
            }
            // Add the current folder to the result and update lastAdded
            result.push_back(currentFolder);
            lastAdded = currentFolder; // Update the last added folder
        }

        return result;
    }
};
