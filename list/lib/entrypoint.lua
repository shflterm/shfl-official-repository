local function getParentPath(path)
    pattern1 = "^(.+)//"
    pattern2 = "^(.+)\\"

    if (string.match(path, pattern1) == nil) then
        return string.match(path, pattern2)
    else
        return string.match(path, pattern1)
    end
end

function entrypoint()
    for _, file in pairs(fs.list(workspace.dir)) do
        if fs.isDir(workspace.dir .. "/" .. file) then
            print("[44m"..file.."/")
        else
            print(file)
        end
    end
end