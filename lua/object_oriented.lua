local Foo = { num = 0 }
Foo.__index = Foo

function Foo:new(o)
    o = o or {}
    self.__index = self
    setmetatable(o, self)
    return o
end

function Foo:test()
    print("Foo:test()", self.num)
end

local Bar = Foo:new()
function Bar:test()
    print("Bar:test()", self.num)
end
local b = Bar:new()

local function search(k, plist)
end