# Copyright (c) 2014-2021 AscEmu Team <http://www.ascemu.org>

set(PATH_PREFIX Northrend/VaultOfArchavon)

set(SRC_NORTHREND_VAULTOFARCHAVON_FILES
   ${PATH_PREFIX}/VaultOfArchavon.cpp
   ${PATH_PREFIX}/VaultOfArchavon.h
)

source_group(Northrend\\VaultOfArchavon FILES ${SRC_NORTHREND_VAULTOFARCHAVON_FILES})
unset(PATH_PREFIX)
