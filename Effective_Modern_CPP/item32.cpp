//ITEM 32 : Use init capture to move objects into closures

#include<iostream>
class Widget
{
public:
	bool isValidated() const;
	bool isProcessed() const;
	bool isArchived() const;
	
private:

};

auto pw = std::make_unique<Widget>();

auto func = [pw = std::move(pw)]
{
	return pw->isValidated() && pw->isArchived();
};