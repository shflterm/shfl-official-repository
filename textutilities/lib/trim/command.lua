function entrypoint()
    local value = text

    if value == nil then
        print("")
        return
    end

    print(value:match'^()%s*$' and '' or value:match'^%s*(.*%S)')
end