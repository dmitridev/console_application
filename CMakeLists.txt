cmake_minimum_required(VERSION 3.7.2)
project(Console_application)




set(SOURCES Menu.cpp Utils.cpp Database.cpp Files.cpp CinemaRecord.cpp )
set(HEADERS Menu.h Utils.h Database.h Files.h CinemaRecord.h )

add_executable(Console_application main.cpp ${SOURCES})


