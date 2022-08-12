#include <iostream>
#include <string>
#include <array>

/**
 * ��������� ���������� ��������� ����� ������� ���������, ���������������
 * ������� �����������. ��������� ������ ��������� ��������� ����������
 * ���������� ���������� ����� ����������, � ������� �� ����� ����.
 */
class ConcreteComponentA;
class ConcreteComponentB;

class Visitor {
public:
    virtual void VisitConcreteComponentA(const ConcreteComponentA* element) const = 0;
    virtual void VisitConcreteComponentB(const ConcreteComponentB* element) const = 0;
};

/**
 * ��������� ���������� ��������� ����� accept, ������� � �������� ���������
 * ����� �������� ����� ������, ����������� ��������� ����������.
 */

class Component {
public:
    virtual ~Component() {}
    virtual void Accept(Visitor* visitor) const = 0;
};

/**
 * ������ ���������� ��������� ������ ����������� ����� accept ����� �������,
 * ����� �� ������� ����� ����������, ��������������� ������ ����������.
 */
class ConcreteComponentA : public Component {
    /**
     * �������� ��������, �� �������� visitConcreteComponentA, ��� �������������
     * �������� �������� ������. ����� ������� �� ��������� ���������� ������, �
     * ����� ������� ���������� �� ��������.
     */
public:
    void Accept(Visitor* visitor) const override {
        visitor->VisitConcreteComponentA(this);
    }
    /**
     * ���������� ���������� ����� ����� ������ ������, �� ����������� � ��
     * ������� ������ ��� ����������. ���������� �� �� ����� ������������ ���
     * ������, ��������� �� ����� � ���������� ������ ����������.
     */
    std::string ExclusiveMethodOfConcreteComponentA() const {
        return "A";
    }
};

class ConcreteComponentB : public Component {
    /**
     * �� �� ����� �����: visitConcreteComponentB => ConcreteComponentB
     */
public:
    void Accept(Visitor* visitor) const override {
        visitor->VisitConcreteComponentB(this);
    }
    std::string SpecialMethodOfConcreteComponentB() const {
        return "B";
    }
};

/**
 * ���������� ���������� ��������� ��������� ������ ������ � ���� �� ���������,
 * ������� ����� �������� �� ����� �������� ���������� �����������.
 *
 * ������������ ������ �� �������� ���������� �� ������������, ��������� ��� ��
 * ������� ���������� ��������, ����� ��� ������ ������������. � ���� ������
 * ���� �� ������� ������� ��������� ������������� ��������� ��������� ���
 * ���������� ������� ���������� ��� ���������� ��������� ���������.
 */
class ConcreteVisitor1 : public Visitor {
public:
    void VisitConcreteComponentA(const ConcreteComponentA* element) const override {
        std::cout << element->ExclusiveMethodOfConcreteComponentA() << " + ConcreteVisitor1\n";
    }

    void VisitConcreteComponentB(const ConcreteComponentB* element) const override {
        std::cout << element->SpecialMethodOfConcreteComponentB() << " + ConcreteVisitor1\n";
    }
};

class ConcreteVisitor2 : public Visitor {
public:
    void VisitConcreteComponentA(const ConcreteComponentA* element) const override {
        std::cout << element->ExclusiveMethodOfConcreteComponentA() << " + ConcreteVisitor2\n";
    }
    void VisitConcreteComponentB(const ConcreteComponentB* element) const override {
        std::cout << element->SpecialMethodOfConcreteComponentB() << " + ConcreteVisitor2\n";
    }
};
/**
 * ���������� ��� ����� ��������� �������� ���������� ��� ����� �������
 * ���������, �� ������� �� ���������� �������. �������� �������� ����������
 * ����� � ��������������� �������� � ������� ����������.
 */
inline void ClientCode(std::array<const Component*, 2> components, Visitor* visitor) {
    // ...
    for (const Component* comp : components) {
        comp->Accept(visitor);
    }
    // ...
}
