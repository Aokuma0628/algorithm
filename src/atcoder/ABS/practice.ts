import { promises as fs } from 'fs';

function mainLogic(
  a: number,
  b: number,
  c: number,
  s: string
): void {
  console.log('%d %s', a + b + c, s);
  return;
}


async function main(
): Promise<void> {
  let text = '';
  let t_arr = [];

  try {
    text = await fs.readFile('/dev/stdin', 'utf8');
  }
  catch (err) {
    console.log(err);
  }

  t_arr = text.split('\n');
  const bc = t_arr[1].split(' ');
  const a = parseInt(t_arr[0], 10);
  const b = parseInt(bc[0], 10);
  const c = parseInt(bc[1], 10);
  const s = t_arr[2];

  mainLogic(a, b, c, s);
  return;
}

main();
