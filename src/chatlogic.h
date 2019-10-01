#ifndef CHATLOGIC_H_
#define CHATLOGIC_H_

#include <vector>
#include <string>
#include "chatgui.h"

// forward declarations
class ChatBot;
class GraphEdge;
class GraphNode;

class ChatLogic
{
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
    std::vector<GraphNode *> _nodes;
    std::vector<GraphEdge *> _edges;

    ////
    //// EOF STUDENT CODE

    // data handles (not owned)
    GraphNode *_currentNode;
    ChatBot *_chatBot;
    ChatBotPanelDialog *_panelDialog;

    // proprietary type definitions
    typedef std::vector<std::pair<std::string, std::string>> tokenlist;

    // proprietary functions
    template <typename T>
    //void AddAllTokensToElement(std::string tokenID, tokenlist &tokens, T &element);
    void AddAllTokensToElement(std::string tokenID, tokenlist &tokens, T *element);    

    template <typename T>
    T *AddToElementList(int id, std::vector<T *> &elements); // checks wether a given edge or node already exist based on their id

public:
    // constructor / destructor
    ChatLogic();
    ~ChatLogic();

    // getter / setter
    //void SetPanelDialogHandle(ChatBotPanelDialog *panelDialog);
    void SetChatbotHandle(ChatBot *chatbot);

    ChatBotPanelDialog *GetChatBotPanelDialog() { return _panelDialog; }
    ChatBot *GetChatBot() { 
        //std::cout << "ChatBot Move Constructor" << std::endl; 
        return _chatBot; 
        }
    void SetPanelDialogHandle(ChatBotPanelDialog *dialog) { _panelDialog = dialog; }

    // proprietary functions
    void LoadAnswerGraphFromFile(std::string filename);
    //void SendMessageToChatbot(std::string message);
    //void SendMessageToUser(std::string message);
    //wxBitmap *GetImageFromChatbot();
};

#endif /* CHATLOGIC_H_ */