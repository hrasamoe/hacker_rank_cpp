#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Message {
public: 
    Message(const string& conten, const int id): content_(conten), id_(id) {
    }
    const string& get_text() const{
        return content_;
    }
    bool operator<(const Message& other) const
    {
        return id_ < other.id_;
    }
private:
    string content_;
    int id_;
};

class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) {
      return  Message(text, current_index_++);
    }

private:
    int current_index_ = 0;
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
        random_shuffle(messages.begin(), messages.end());         
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
