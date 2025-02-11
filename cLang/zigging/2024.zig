const std = @import("std");

pub fn main() !void {
    const filename = "../advent1.txt";

    const file = try std.fs.cwd().openFile(filename, .{});
    defer file.close();

    // Create a buffer to store file contents
    var buffer: [1024]u8 = undefined;
    var array1: [1024]i32 = .{0} ** 1024;
    var array2: [1024]i32 = .{0} ** 1024;
    var len: usize = 0;
    const reader = file.reader();

    var line = try reader.readUntilDelimiter(&buffer, '\n');
    while (true) {
        // std.debug.print("{s}\n", .{line});
        var idx_n1: usize = 0;
        for (line, 0..) |l, idx| {
            if (l == ' ') {
                idx_n1 = idx;
                break;
            }
        }
        var idx_n21: usize = 0;
        for (line[idx_n1..], 0..) |l, idx| {
            if (l != ' ') {
                idx_n21 = idx_n1 + idx;
                break;
            }
        }
        const idx_n22: usize = line.len;

        const n1 = line[0..idx_n1];
        const n2 = line[idx_n21..idx_n22];
        // std.debug.print("n1={s} n2={s}\n", .{ n1, n2 });

        const number1 = try std.fmt.parseInt(i32, n1, 10);
        const number2 = try std.fmt.parseInt(i32, n2, 10);

        array1[len] = number1;
        array2[len] = number2;
        // std.debug.print("n1={} n2={}\n", .{ number1, number2 });
        len += 1;

        line = reader.readUntilDelimiter(&buffer, '\n') catch {
            std.debug.print("file terminated. Lines {}\n", .{len});
            break;
        };
    }

    var array_left = array1[0..len];
    var array_right = array2[0..len];

    insertion_sort(&array_left);
    insertion_sort(&array_right);
    std.debug.print("array1={any}", .{array_left});

    var distance: usize = 0;
    std.debug.print("len {}\n", .{len});
    for (0..len) |idx| {
        distance += @intCast(@abs(array_left[idx] - array_right[idx]));
    }
    std.debug.print("count {}\n", .{distance});
    test_order(array_left);
    test_order(array_right);

    const similarity = try simlilarity_array(array_left, array_right);
    std.debug.print("similarity {}\n", .{similarity});
}

fn test_order(arr: []i32) void {
    for (0..arr.len - 1) |idx| {
        if (arr[idx + 1] < arr[idx]) {
            std.debug.print("ta errado\n", .{});
        }
    }
}

fn insertion_sort(arr: *[]i32) void {
    const arr_use = arr.*;
    for (0..arr.len) |idx| {
        var aux_var = idx;
        while (aux_var > 0 and arr_use[aux_var] < arr_use[aux_var - 1]) {
            const v = arr_use[aux_var];
            arr_use[aux_var] = arr_use[aux_var - 1];
            arr_use[aux_var - 1] = v;
            aux_var -= 1;
        }
    }
}

fn simlilarity_array(arr1: []i32, arr2: []i32) !usize {
    var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
    defer arena.deinit();

    const allocator = arena.allocator();

    var hash = std.hash_map.AutoHashMap(i32, i32).init(allocator);
    defer hash.deinit();
    for (arr2) |v| {
        if (hash.contains(v)) {
            const v_prev = hash.get(v).?;
            try hash.put(v, v_prev + 1);
        } else {
            try hash.put(v, 1);
        }
    }
    var similarity: usize = 0;
    for (arr1) |v| {
        if (hash.contains(v)) {
            similarity += @intCast(v * hash.get(v).?);
        }
    }
    return similarity;
}