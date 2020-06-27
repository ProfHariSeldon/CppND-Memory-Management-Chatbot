#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////
  
    // Causes segmentation fault upon closing chatbot window because ~ChatBot() destructor is called twice.  Once here and once in chatgui.cpp.
    // That is why this delete is commented out
    // delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

// https://github.com/VD2410/CppND-Memory-Management-Chatbot/blob/master/src/graphnode.cpp
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    // https://knowledge.udacity.com/questions/249351
    // https://github.com/Lee0326/CppND-Memory-Management-Chatbot/blob/master/src/graphnode.cpp
    // _childEdges.push_back(edge);
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////

// https://github.com/Lee0326/CppND-Memory-Management-Chatbot/blob/master/src/graphnode.cpp
// void GraphNode::MoveChatbotHere(ChatBot *chatbot)
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    // https://knowledge.udacity.com/questions/249351
    // https://github.com/Lee0326/CppND-Memory-Management-Chatbot/blob/master/src/graphnode.cpp
    // _chatBot = chatbot;
    _chatBot = std::move(chatbot);
    // https://github.com/Lee0326/CppND-Memory-Management-Chatbot/blob/master/src/graphnode.cpp
    // _chatBot->SetCurrentNode(this);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    // https://knowledge.udacity.com/questions/249351
    // https://github.com/Lee0326/CppND-Memory-Management-Chatbot/blob/master/src/graphnode.cpp
    // newNode->MoveChatbotHere(_chatBot);
    newNode->MoveChatbotHere(std::move(_chatBot));
    // https://github.com/Lee0326/CppND-Memory-Management-Chatbot/blob/master/src/graphnode.cpp
    // _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    // https://github.com/VD2410/CppND-Memory-Management-Chatbot/blob/master/src/graphnode.cpp
    // return _childEdges[index];
    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}