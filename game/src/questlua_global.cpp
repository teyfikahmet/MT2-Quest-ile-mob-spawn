void RegisterGlobalFunctionTable(lua_State* L)

// ARAT ÜSTÜNE EKLE

int mob_spawn_ext(lua_State* L)
{
	if(false == lua_isnumber(L, 1) || false == lua_isnumber(L, 2) || false == lua_isnumber(L, 3)
			|| false == lua_isnumber(L, 4) || false == lua_isnumber(L, 5) || false == lua_isboolean(L, 6) )
	{
			lua_pushnumber(L, 0);
			return 0;
	}

	const DWORD mobVnum = static_cast<DWORD>(lua_tonumber(L, 1));
	const long mapIndex = static_cast<long>(lua_tonumber(L, 2));
	const int x = static_cast<int>(lua_tonumber(L, 3));
	const int y = static_cast<int>(lua_tonumber(L, 4));
	const size_t count = MINMAX(1, static_cast<size_t>(lua_tonumber(L, 5)), 10);
	const bool isAggresive = static_cast<bool>(lua_toboolean(L, 6));


	size_t SpawnCount = 0;

	const CMob* pMonster = CMobManager::instance().Get( mobVnum );

	if( NULL != pMonster )
	{
			//const LPCHARACTER pChar = CQuestManager::instance().GetCurrentCharacterPtr();
			for( size_t i=0 ; i < count ; ++i )
				{
					const LPCHARACTER pSpawnMonster = CHARACTER_MANAGER::instance().SpawnMobRange( mobVnum,
									mapIndex,
									x - number(100, 200),
									y - number(100, 200),
									x + number(100, 200),
									y + number(100, 200),
									true,
									pMonster->m_table.bType == CHAR_TYPE_STONE,
									isAggresive );

					if( NULL != pSpawnMonster )
					{
							++SpawnCount;
					}
			}

			sys_log(0, "QUEST Spawn Monstster: VNUM(%u) COUNT(%u) isAggresive(%b)", mobVnum, SpawnCount, isAggresive);
	}

	lua_pushnumber(L, SpawnCount);

	return 1;
}
//#########################################################
{    "spawn_mob",                    _spawn_mob                        },
// ARAT ALTINA EKLE
{    "spawn_mob_ext",                    mob_spawn_ext                        },
