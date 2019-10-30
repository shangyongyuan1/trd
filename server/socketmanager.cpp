#include "socketmanager.h"

SocketManager* SocketManager::instance = nullptr;
QMutex SocketManager::mutex;

SocketManager::SocketManager()
{

}

SocketManager* SocketManager::getInstance ()
{
    if(instance == nullptr){
        mutex.lock();
        if(instance == nullptr){
            instance = new SocketManager();
        }
        mutex.unlock();
    }
    return instance;
}
void SocketManager::insertSocket(ClientSocket *cs)
{
    sockets.push_back (cs);
}

vector<ClientSocket*> SocketManager::getAllSocket()const
{
    return sockets;
}


