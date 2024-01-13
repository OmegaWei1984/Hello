local t1 = {
    [1] = 'a',
    [2] = 'b',
    [3] = 'c',
    -- [3] = nil,
    [4] = 'd',
    ['f'] = 'f',
    [6] = 'g'
}

for i,v in ipairs(t1) do
    print(i, v)
end

print()

for i,v in pairs(t1) do
    print(i, v)
end
