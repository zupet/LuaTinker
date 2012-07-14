-- 전역 g_test 의 멤버 변수 _test 의 값을 출력한다.
print(g_test._test)

-- const char* test::is_test() 함수의 결과를 출력한다.
print(g_test:is_test())

-- test::ret_int() 함수의 결과물을 출력한다.
print(g_test:ret_int())

-- temp 에 새 test 객체를 만들어 넣는다.
temp = test(4)

-- test 의 멤버 변수 _test 값을 출력한다.
print(temp._test)

-- Lua 에 추가되지 않은 A 구조체값을 a라는 변수에 넣는다.
a = g_test:get()

-- 임의의 객체 a를 Lua->C++로 전달한다.
temp:set(a)

-- test::set(A a) 함수 호출로 _test 에 생긴 변화를 확인한다.
print(temp._test)

-- 상속받은 부모의 함수 호출
print(temp:is_base())

-- 자기 자신의 함수 호출
print(temp:is_test())

-- 어떠한 객체의 metatable을 통해 등록된 클래스와 그 함수들을 살펴보는 함수
-------------------------------------------------------------------------------
function objinfo(obj)

	local meta = getmetatable(obj)
	if meta ~= nil then
		metainfo(meta)
	else
		print("no object infomation !!")
	end
end

function metainfo(meta)

	if meta ~= nil then
		local name = meta["__name"]
		if name ~= nil then
			metainfo(meta["__parent"])
			print("<"..name..">")
			for key,value in pairs(meta) do 
				if not string.find(key, "__..") then 
					if type(value) == "function" then
						print("\t[f] "..name..":"..key.."()") 
					elseif type(value) == "userdata" then
						print("\t[v] "..name..":"..key)
					end
				end
			end
		end
	end
end
-------------------------------------------------------------------------------

-- Lua 에서 객체는 userdata로 인식된다.
print("g_test	-> ", g_test)
print("temp	-> ", temp)
print("a	-> ", a)

-- C++ 에서 등록한 g_test 의 객체 정보를 살펴본다.
print("objinfo(g_test)")
objinfo(g_test)

-- constructor 를 통해 생성한 temp 객체 정보를 살펴본다.
print("objinfo(temp)")
objinfo(temp)

-- 등록하지 않은 A 구조체 형의 a 객체 정보를 살펴본다.
print("objinfo(a)")
objinfo(a)

