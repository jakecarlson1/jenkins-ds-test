#define CATCH_CONFIG_MAIN

#include <cstddef>

#include "catch.hpp"

#include "linkedlist.h"
#include "queue.h"
#include "stack.h"

TEST_CASE("LinkedList class", "[LinkedList]")
{

    SECTION("Default constructor")
    {
        LinkedList<int> list;

        REQUIRE(list.getLength() == 0);
        REQUIRE(list.getHead() == nullptr);
    }

    SECTION("Constructor with head")
    {
        LinkedList<int> list (2);

        REQUIRE(list.getHead() != nullptr);
        REQUIRE(list.getHead()->getData() == 2);
        REQUIRE(list.getHead()->getNext() == nullptr);
        REQUIRE(list.getHead()->getLast() == nullptr);
    }

    SECTION("Copy constructor")
    {
        LinkedList<int> list1 (1);
        LinkedList<int> list2 (list1);

        REQUIRE(list2.getHead() != nullptr);
        REQUIRE(list2.getHead()->getData() == 1);
        REQUIRE(list2.getHead()->getNext() == nullptr);
        REQUIRE(list2.getHead()->getLast() == nullptr);
        REQUIRE(list2.size() == list1.size());

        list1.add(2);
        LinkedList<int> list3 (list1);
        REQUIRE(list3.get(0) == list1.get(0));
        REQUIRE(list3.get(1) == list1.get(1));
        REQUIRE(list3.size() == list1.size());

    }

    SECTION("add")
    {
        LinkedList<int> list;
        list.add(1);
        list.add(2);
        list.add(3);

        REQUIRE(list.getHead()->getData() == 1);
//        REQUIRE(list.getHead()->getLast() == nullptr);
//        std::cout << list.getHead()->getLast() << std::endl;
        REQUIRE(list.getHead()->getNext()->getData() == 2);
//        REQUIRE(list.getHead()->getNext()->getLast() == list.getHead());
        REQUIRE(list.getHead()->getNext()->getNext()->getData() == 3);
//        REQUIRE(list.getHead()->getNext()->getNext()->getLast() == list.getHead()->getNext());
    }

    SECTION("addToFront")
    {
        LinkedList<int> list;
        list.addToFront(1);
        REQUIRE(list.getHead()->getData() == 1);
        REQUIRE(list.size() == 1);
        list.addToFront(2);
        REQUIRE(list.getHead()->getData() == 2);
        REQUIRE(list.size() == 2);
        list.addToFront(3);
        REQUIRE(list.getHead()->getData() == 3);
        REQUIRE(list.size() == 3);
    }

    SECTION("get")
    {
        LinkedList<int> list;

        list.add(1);
        REQUIRE(list.get(0) == 1);
        REQUIRE(list.get(-1) == 1);

        list.add(2);
        REQUIRE(list.get(0) == 1);
        REQUIRE(list.get(1) == 2);
        REQUIRE(list.get(-1) == 2);
        REQUIRE(list.get(-2) == 1);

        list.addToFront(0);
        REQUIRE(list.get(0) == 0);
        REQUIRE(list.get(1) == 1);
        REQUIRE(list.get(2) == 2);
        REQUIRE(list.get(-1) == 2);
        REQUIRE(list.get(-2) == 1);
        REQUIRE(list.get(-3) == 0);
    }

    SECTION("size")
    {
        LinkedList<int> list;
        REQUIRE(list.size() == 0);
        list.add(1);
        REQUIRE(list.size() == 1);
        list.add(2);
        REQUIRE(list.size() == 2);
        list.addToFront(0);
        REQUIRE(list.size() == 3);
    }

    SECTION("remove")
    {
        LinkedList<int> list(0);
        list.add(1);
        list.add(2);

        list.remove(0);
        REQUIRE(list.size() == 2);
        REQUIRE(list.get(1) == 2);

        list.remove(1);
        REQUIRE(list.size() == 1);
        REQUIRE(list.get(0) == 1);
    }

    SECTION("[] operator"){

    }

    SECTION("assignment operator"){

    }


}

TEST_CASE("Stack class", "[stack]"){

    SECTION("Push"){

    }

    SECTION("Pop"){

    }

    SECTION("Peek"){

    }

}

TEST_CASE("Queue class", "[queue]"){

    SECTION("Enqueue"){

    }

    SECTION("Dequeue"){

    }

    SECTION("Peek"){

    }

}
