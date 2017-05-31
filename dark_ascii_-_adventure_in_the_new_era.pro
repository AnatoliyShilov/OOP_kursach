TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    item.cpp \
    damagetypes.cpp \
    armor.cpp \
    weapon.cpp \
    accessory.cpp \
    allitems.cpp \
    bag.cpp \
    medkit.cpp \
    actor.cpp \
    coordinates.cpp \
    npc.cpp \
    allnpc.cpp \
    player.cpp \
    cell.cpp \
    room.cpp \
    level.cpp \
    controller.cpp \
    traidecontroller.cpp \
    inventorycontroller.cpp \
    lvlupcontroller.cpp \
    abstractcontroller.cpp \
    battlecontroller.cpp

HEADERS += \
    item.h \
    damagetypes.h \
    armor.h \
    weapon.h \
    accessory.h \
    allitems.h \
    bag.h \
    medkit.h \
    actor.h \
    coordinates.h \
    npc.h \
    allnpc.h \
    player.h \
    cell.h \
    room.h \
    level.h \
    controller.h \
    dynamic.h \
    additionfunction.h \
    traidecontroller.h \
    inventorycontroller.h \
    lvlupcontroller.h \
    abstractcontroller.h \
    battlecontroller.h
