#define lua_c
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lua.h"

#include "lauxlib.h"
#include "lualib.h"

int main()
{
	lua_State *L = luaL_newstate();
	if (L == NULL)
	{
		return 1;
	}
	luaL_openlibs(L);

	int ret = luaL_loadfile(L, "main.lua");

	if (ret)
	{
		printf("Lua doFile Error !\n");
		exit(1);
	}
	if (lua_pcall(L, 0, 0, 0) != LUA_OK)
	{
		printf("pcall error \n");
		return 1;
	}
	lua_getglobal(L, "width");
	int width = lua_tonumber(L, -1);
	lua_pop(L, 1);
	printf("%d\n", width);

}