#include "chatmanager.h"


ChatManager *ChatManager::instance = nullptr;
QMutex ChatManager::mutex;

ChatManager::ChatManager()
{

}


ChatManager* ChatManager::getInstance()
{
    if(instance == nullptr)
    {
        mutex.lock();
        if(nullptr == instance)
        {
            instance = new ChatManager();
        }
        mutex.unlock();
    }
    return instance;
}
void ChatManager::insertChat(const Chat& chat)
{
    chatrooms.push_back (chat);
}

void ChatManager::eraseChat(const QString& name)
{
    vector<Chat>::iterator it;
    for(it = chatrooms.begin (); it != chatrooms.end (); ++it)
    {
        Chat chat = *it;
        if(chat.getUserName () == name)
        {
            chatrooms.erase (it);
            break;
        }
    }
}


vector<Chat> ChatManager::getAllChat()const
{
    return chatrooms;
}
