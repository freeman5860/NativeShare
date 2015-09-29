//
//  native_share_binder.cpp
//
//  Created by Freeman on 15/9/29.
//  Copyright (c) 2015Äê Gideros Mobile. All rights reserved.
//

#include "gnative_share.h"
#include "gideros.h"
#include <vector>
#include <string>

static int shareText(lua_State *L)
{
    gnativeshare_ShareText(luaL_checkstring(L, 1));
    
    return 0;
}

static int shareImage(lua_State *L)
{
    gnativeshare_ShareImage();
    
    return 0;
}

static int loader(lua_State* L)
{
    lua_newtable(L);
    
    lua_pushcfunction(L, shareText);
    lua_setfield(L, -2, "shareText");
    lua_pushcfunction(L, shareImage);
    lua_setfield(L, -2, "shareImage");
    
    lua_pushvalue(L, -1);
    lua_setglobal(L, "nativeshare");
    
    return 1;
}

static void g_initializePlugin(lua_State *L)
{
    lua_getglobal(L, "package");
    lua_getfield(L, -1, "preload");
    
    lua_pushcfunction(L, loader);
    lua_setfield(L, -2, "nativeshare");
    
    lua_pop(L, 2);
}

static void g_deinitializePlugin(lua_State *L)
{
}

REGISTER_PLUGIN("nativeshare", "1.0")