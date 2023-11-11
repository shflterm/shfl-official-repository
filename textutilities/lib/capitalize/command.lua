function entrypoint()
    local value = text

    if value == nil then
        print("")
        return
    end

    value = value:gsub("%a", string.upper, 1)
    print(value)
end