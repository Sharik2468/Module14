#include "Command.cpp"
#include "Observer.cpp"
#include "Visitor.cpp"
#include "State.cpp"
#include "TemplateMethod.cpp"

int main() {
	//Command
	Invoker* invoker = new Invoker;
	invoker->SetOnStart(new SimpleCommand("Say Hi!"));
	Receiver* receiver = new Receiver;
	invoker->SetOnFinish(new ComplexCommand(receiver, "Send email", "Save report"));
	invoker->DoSomethingImportant();

	delete invoker;
	delete receiver;

	std::cout << std::endl;

	//Observer
	ClientCode();

	std::cout << std::endl;

	//Visitor
	std::array<const Component*, 2> components = { new ConcreteComponentA, new ConcreteComponentB };
	std::cout << "The client code works with all visitors via the base Visitor interface:\n";
	ConcreteVisitor1* visitor1 = new ConcreteVisitor1;
	ClientCode(components, visitor1);
	std::cout << "\n";
	std::cout << "It allows the same client code to work with different types of visitors:\n";
	ConcreteVisitor2* visitor2 = new ConcreteVisitor2;
	ClientCode(components, visitor2);

	for (const Component* comp : components) {
		delete comp;
	}
	delete visitor1;
	delete visitor2;

	std::cout << std::endl;

	//State
	ClientCodeState();

	std::cout << std::endl;

	//TemplateMethod
	std::cout << "Same client code can work with different subclasses:\n";
	ConcreteClass1* concreteClass1 = new ConcreteClass1;
	ClientCode(concreteClass1);
	std::cout << "\n";
	std::cout << "Same client code can work with different subclasses:\n";
	ConcreteClass2* concreteClass2 = new ConcreteClass2;
	ClientCode(concreteClass2);
	delete concreteClass1;
	delete concreteClass2;

	return 0;
}