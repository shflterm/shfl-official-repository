function entrypoint()
    local target = name
    if target == nil then
        error("No path specified.")
    end
    if not fs.exists(target) then
        error("Path does not exist.")
    end

    fs.mkDir(target)
end