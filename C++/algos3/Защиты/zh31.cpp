#include <iostream>
#include <vector>
#include <memory>

const int MOD = 1e9+7;

struct Node {
    int value;
    std::shared_ptr<Node> next;
    Node(int v, std::shared_ptr<Node> n = nullptr) : value(v), next (n) {}
};

class PersistentStack {
public:
    PersistentStack() : head(nullptr) {}

    PersistentStack(const std::shared_ptr<Node>& h): head(h) {}
    PersistentStack push(int value) {
        return PersistentStack(std::make_shared<Node>(value, head));
    }

    PersistentStack pop() {
        if (head) {
            return PersistentStack(head->next);
        }
        return *this;
    }

    int top() const {
        return head ? head->value : 0;
    }

private:
    std::shared_ptr<Node> head;
};

int main() {
    int Q;
    std::cin >> Q;

    std::vector<PersistentStack> stacks;
    stacks.emplace_back();

    long long res = 1;
    for (int i = 0; i < Q; ++i) {
        int Si, Xi;
        std::cin >> Si >> Xi;
    
    PersistentStack newStack = stacks[i];

    if (Xi > 0) {
        newStack = newStack.push(Xi);
    }else {
        newStack = newStack.pop();
    }
    
    stacks.push_back(newStack);
    }

    for (const auto& stack : stacks) {
        int tops = stack.top();
        if (tops > 0) {
            res = (res * tops) % MOD;
        }
    }

    std::cout << res;
    return 0;
}