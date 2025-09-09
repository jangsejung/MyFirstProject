#!/usr/bin/env python3
import argparse, json, os, datetime
import sys

DB_PATH = "todo.json"

def load():
    if not os.path.exists(DB_PATH):
        return []
    with open(DB_PATH, "r", encoding="utf-8") as f:
        try:
            return json.load(f)
        except json.JSONDecodeError:
            return []

def save(items):
    with open(DB_PATH, "w", encoding="utf-8") as f:
        json.dump(items, f, ensure_ascii=False, indent=2)

def cmd_add(args):
    items = load()
    items.append({
        "id": (items[-1]["id"] + 1) if items else 1,
        "text": " ".join(args.text),
        "done": False,
        "created_at": datetime.datetime.now().isoformat(timespec="seconds")
    })
    save(items)
    print(f"✅ 추가: {items[-1]['id']}. {items[-1]['text']}")

def cmd_list(_):
    items = load()
    if not items:
        print("📭 비어있습니다. `python3 main.py add ...` 로 추가해 보세요.")
        return
    print("📝 TODO 목록")
    for it in items:
        mark = "✔" if it["done"] else "•"
        print(f"{mark} {it['id']:>2}: {it['text']}  (생성:{it['created_at']})")

def cmd_done(args):
    items = load()
    for it in items:
        if it["id"] == args.id:
            it["done"] = True
            save(items)
            print(f"🎉 완료 처리: {it['id']}. {it['text']}")
            return
    print("❌ 해당 ID를 찾을 수 없습니다.")

def cmd_clear(_):
    save([])
    print("🧹 전체 삭제 완료")

def main():
    parser = argparse.ArgumentParser(prog="todo", description="초간단 CLI 투두앱")
    sub = parser.add_subparsers(dest="cmd")

    p_add = sub.add_parser("add", help="할 일 추가")
    p_add.add_argument("text", nargs="+", help="할 일 내용")
    p_add.set_defaults(func=cmd_add)

    p_list = sub.add_parser("list", help="목록 보기")
    p_list.set_defaults(func=cmd_list)

    p_done = sub.add_parser("done", help="ID로 완료 처리")
    p_done.add_argument("id", type=int)
    p_done.set_defaults(func=cmd_done)

    p_clear = sub.add_parser("clear", help="전체 삭제")
    p_clear.set_defaults(func=cmd_clear)

    # 명령어 없이 실행하면 list 동작
    if len(sys.argv) == 1:
        cmd_list(None)
    else:
        args = parser.parse_args()
        args.func(args)

if __name__ == "__main__":
    main()
