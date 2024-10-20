struct Robot{
    int position;
    int health;
    char direction;
    int displayOrder;

    Robot(int position, int health, char direction, int displayOrder) {
        this->position = position;
        this->health = health;
        this->direction = direction;
        this->displayOrder = displayOrder;
    }

    bool operator< (Robot &rhs) {
        return this->position < rhs.position;
    }
};

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<Robot> robots;
        for (int i = 0; i < positions.size(); i++)
            robots.emplace_back(positions[i], healths[i], directions[i], i);
        
        sort(robots.begin(), robots.end());

        stack<pair<int, int>> collidingRobots;
        vector<pair<int, int>> survivedRobots;
        for (int i = 0; i < robots.size(); i++) {
            char direction = robots[i].direction;
            int health = robots[i].health;
            if (direction == 'L') {
                while(!collidingRobots.empty() && health > 0) {
                    int rightRobotHealth = collidingRobots.top().second;
                    int rightRobotOrder = collidingRobots.top().first;
                    collidingRobots.pop();

                    if (rightRobotHealth > health) {
                        collidingRobots.emplace(rightRobotOrder, rightRobotHealth - 1);
                        health = 0;
                        break;
                    }
                    else if (rightRobotHealth < health) {
                        health--;
                    }
                    else {
                        health = 0;
                        break;
                    }
                }
                if (health > 0)
                    survivedRobots.emplace_back(robots[i].displayOrder, health);        
            }
            else if (direction == 'R') {
                collidingRobots.emplace(robots[i].displayOrder, health);
            }
        }

        while(!collidingRobots.empty()) {
            survivedRobots.push_back(collidingRobots.top());
            collidingRobots.pop();
        }

        sort(survivedRobots.begin(), survivedRobots.end());
        
        vector<int> ans;
        for (auto &[_, health]: survivedRobots)
            ans.push_back(health);

        return ans;
    }
};

/*

- stack of the maximum leftmost robot that is going to the right.
- if current robot is going left and the stack is empty, 
    then the current robot survives. 

*/