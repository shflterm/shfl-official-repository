function entrypoint()
    local from = source
    local to = destination
    if from == nil then
        error("No source path specified.")
    end
    if to == nil then
        error("No destination path specified.")
    end
    if not fs.exists(from) then
        error("Source path does not exist.")
    end
    if fs.exists(to) then
        error("Destination path already exists.")
    end

    fs.copy(from, to)
end