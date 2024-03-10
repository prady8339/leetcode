class Solution {
private:
    void justifyLine(string &line, int maxWidth){
        while(!line.empty() && line.back() == ' ') line.pop_back();
        string justifiedLine;
        int countSpaces = 0;
        int lineLength = line.size();
        for(auto &x : line) if(x == ' ') countSpaces++;
        if(countSpaces == 0){
            while(line.size() < maxWidth) line.push_back(' ');
            return ;
        }
        int spaceToAdd = (maxWidth - lineLength) / countSpaces;
        int addOn = (maxWidth - lineLength) % countSpaces;
        for(int i = 0 ; i < line.size() ; i++){
            if(line[i] == ' '){
                int temp = spaceToAdd + (addOn > 0);
                addOn--;
                while(temp){
                    justifiedLine += " ";
                    temp--;
                }
            }
            justifiedLine.push_back(line[i]);
        }
        while(justifiedLine.size() < maxWidth) justifiedLine.push_back(' ');
        line = justifiedLine;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        string line ;
        for(auto &word : words){

            if(line.size() + word.size() > maxWidth){
                justifyLine(line,maxWidth);
                ans.push_back(line);
                line = "";
            }

            line += word;
            if(line.size() < maxWidth){
                line += " ";
            }
        }
        while(line.size() < maxWidth) line.push_back(' ');
        ans.push_back(line);

        return ans;
    }
};