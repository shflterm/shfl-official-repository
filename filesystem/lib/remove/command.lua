function entrypoint()
    local target = path
    if target == nil then
        error("No source path specified.")
    end
    if not fs.exists(target) then
        error("Source path does not exist.")
    end

    fs.remove(target)
    return fs.absolute(target)
end